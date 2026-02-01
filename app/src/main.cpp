#include <borealis.hpp>
#include "activity/main_activity.hpp"
#include "utils/config.hpp"

int main(int argc, char* argv[]) {
    // Initialize Borealis
    if (!brls::Application::init()) {
        brls::Logger::error("Failed to initialize Borealis");
        return EXIT_FAILURE;
    }

    // Set application metadata
    brls::Application::createWindow("SwitchEmby");

    // Load configuration
    emby::utils::Config::getInstance().load("/switch/switchemby/config.json");

    // Push main activity
    brls::Application::pushActivity(new emby::activity::MainActivity());

    // Run the application
    while (brls::Application::mainLoop());

    return EXIT_SUCCESS;
}
