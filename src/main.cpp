#include <iostream>
#include <string>
#include "spotifydbus.hpp"

int main()
{
    Spotify::SpotifyDBus client;
    std::cout << client.metadata().m_autoRating << std::endl;
}


