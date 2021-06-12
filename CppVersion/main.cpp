#include "Finder.hpp"
#include <pthread.h>
#include <chrono>

#define FILEPATH "../../teledb_cleaned.csv"
#define ONLYIDFILEPATH "../../teledb_only_id.csv"
#define NUM_THREADS 1

using namespace std;

void *Boot(void *finder) {
    Finder* finder_ = (Finder*)finder;
    auto t1 = chrono::high_resolution_clock::now();
    finder_->boot();
    auto t2 = chrono::high_resolution_clock::now();
    auto ms_int = chrono::duration_cast<chrono::milliseconds>(t2 - t1);
    if (finder_->getShowTime())
        cout << "boot time: " << ms_int.count() << "ms\n";
    pthread_exit(NULL);
}


int main(int argc, char *argv[]){
    Finder finder(FILEPATH);
    for (int i = 1; i < argc ; i ++){
        string arg = argv[i];
        if (arg == "-id") {
            finder.setPath(ONLYIDFILEPATH);
            cout<<"Warning: using onlyID dataset, results might be incomplete."<<endl;
        }else if (arg == "-st"){
            finder.setShowTime(true);
            cout<<"Warning: showing boot time."<<endl;
        }
    }
    
    pthread_t threads[NUM_THREADS];

    for(int i = 0; i < NUM_THREADS; i++) {
        int rc = pthread_create(&threads[i], NULL, Boot, (void *)&finder);
    }
    finder.run();
}