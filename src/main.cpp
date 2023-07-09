#include <iostream>
#include <string>
#include "spotifydbus.hpp"

int main(int argc, char *argv[])
{
    Spotify::SpotifyDBus client;
    std::cout << client.metadata().m_autoRating << std::endl;
}


