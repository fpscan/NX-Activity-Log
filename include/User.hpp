#ifndef USER_H
#define USER_H

#include <SDL2/SDL.h>
#include <string>
#include <switch.h>

// The User class stores all relevant/useful information about a user
// on the console. All this is read using the provided userID
class User {
    private:
        // The selected user's ID (set to zero when an error occurs)
        u128 ID;
        // The user's username
        std::string username;
        // The user's profile image
        SDL_Texture * image;

    public:
        User(u128, std::string, SDL_Texture *);

        // Returns private members
        u128 getID();
        std::string getUsername();
        SDL_Texture * getImage();

        // Destructor frees texture if necessary
        ~User();
};

#endif