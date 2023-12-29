#ifndef PROCESSSIMULATION_PAGESTRUCT_H
#define PROCESSSIMULATION_PAGESTRUCT_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>

#define PRECISION 3

struct Page{
    char data;
    unsigned int creationTime;
    unsigned int lastAccessTime;
    unsigned int replaceTime;

    Page(char data, unsigned int creationTime) : data(data), creationTime(creationTime) {
        lastAccessTime = creationTime;
        replaceTime = -1; // Will create funny numbers in output, but it's better than 0 :)
    }
};

struct PageAlgorithmResult{
    unsigned int pageFaults;
    unsigned int pageHits;
    unsigned int numberOfPages;
    double pageHitsRatio; // hits/(hits+faults)
    double pageFaultsRatio; // faults/(hits+faults)
    double averageLifetime; // (replaceTime - creationTime)/numberOfPages

    PageAlgorithmResult(unsigned int pageFaults, unsigned int pageHits, const std::vector<Page>& pages) : pageFaults(
            pageFaults), pageHits(pageHits), numberOfPages(pages.size()) {
        pageHitsRatio = (double)pageHits/(pageHits+pageFaults);
        pageFaultsRatio = (double)pageFaults/(pageHits+pageFaults);
        averageLifetime = 0;
        for(auto page : pages){
            if(page.replaceTime == -1) continue; // Don't count the pages that were never replaced
            averageLifetime += (double)(page.replaceTime - page.creationTime);
        }
        averageLifetime /= numberOfPages;
    }

    PageAlgorithmResult() = delete;

    friend std::ostream& operator<<(std::ostream& o, PageAlgorithmResult& page){
        // Page faults;Page hits;Number of pages;Page hits ratio;Page faults ratio;Average lifetime
        o << std::fixed << std::setprecision(PRECISION);
        return o << page.pageFaults << ';' << page.pageHits << ';' << page.numberOfPages << ';' << page.pageHitsRatio << ';' << page.pageFaultsRatio << ';' << page.averageLifetime << std::endl;
    }
};

#endif //PROCESSSIMULATION_PAGESTRUCT_H
