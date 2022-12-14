// cursovaya.cpp: определяет точку входа для приложения.
//

#include "cursovaya.h"


std::string getToken();

std::string ocrImageFile(std::string filename);

void initialTesseract();

void freeTesseract();

tesseract::TessBaseAPI* tesseractApi = nullptr;

int main() {

    initialTesseract();
    TgBot::Bot bot(getToken());
    bot.getEvents().onCommand("start", [&bot](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Hi!");
        });
    bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) {
        printf("User wrote %s\n", message->text.c_str());
        if (StringTools::startsWith(message->text, "/start")) {
            return;
        }
        bot.getApi().sendMessage(message->chat->id, "Your message is: " + message->text);
        });
    try {
        printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
        TgBot::TgLongPoll longPoll(bot);
        while (true) {
            printf("Long poll started\n");
            longPoll.start();
        }
    }
    catch (TgBot::TgException& e) {
        printf("error: %s\n", e.what());
    }
    freeTesseract();
    return 0;
}

std::string getToken() {
    std::ifstream file("config/token.txt");
    std::string token;
    file >> token;
    file.close();
    return token;
}

std::string ocrImageFile(std::string filename) {
    

    return "";
}

void initialTesseract() {
    
    tesseractApi = new tesseract::TessBaseAPI();
    if (tesseractApi->Init(NULL, "eng")) {
        fprintf(stderr, "Could not initialize tesseract.\n");
        exit(2);
    }
}

void freeTesseract() {

}


