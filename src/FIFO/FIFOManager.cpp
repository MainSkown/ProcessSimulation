#include "FIFOManager.h"
#include "../Config/Config.h"
#include <algorithm>
#include "../Utils/ProgressBar.h"

PageAlgorithmResult FIFOManager::CreateSimulation(std::string reference_string) {
    unsigned int page_faults = 0;
    unsigned int page_hits = 0;

    std::vector<Page*> frame(Config::getConfig().frameSize, nullptr);
    std::vector<Page> pages;

    unsigned int ticks = 0;

    for(auto &c : reference_string) {
        // Check if page is already in frame
        using std::begin;
        using std::end;
        if(std::any_of(frame.begin(), frame.end(), [&c](Page* p){return p != nullptr && p->data == c;})) {
            page_hits++;
            goto next;
        }

        // Check if frame has an empty slot
        for(int i = 0; i < Config::getConfig().frameSize; i++) {
            if(frame[i] == nullptr) {
                frame[i] = new Page(c, ticks);
                pages.push_back(*frame[i]);
                page_faults++;
                goto next;
            }
        }

        // Replace the oldest page
        {
            auto oldest = std::min_element(frame.begin(), frame.end(),
                                           [](Page *a, Page *b) { return a->creationTime < b->creationTime; });
            oldest[0]->replaceTime = ticks;
            pages.push_back(*oldest[0]);
            oldest[0] = new Page(c, ticks);
            page_faults++;
            goto next;
        }

        next:
            ticks++;
            //ProgressBar::PrintBar(ticks, reference_string.size(), name);
    }

    return PageAlgorithmResult{page_faults, page_hits, pages};
}
