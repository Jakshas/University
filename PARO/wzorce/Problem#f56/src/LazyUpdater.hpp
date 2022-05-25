#include "Updater.hpp"
#include "GreeterUpdater.hpp"

class LazyUpdater: public Updater{
    private:
    std::unique_ptr<GreeterUpdater> updater;
    public:

        void checkForUpdates(){
            if (!updater)
            {
                updater = std::make_unique<GreeterUpdater>();
            }
            updater->checkForUpdates();
        }
};
