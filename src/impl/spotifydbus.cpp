#include <iostream>
#include <tuple>
#include "spotifydbus.hpp"
#include "dbus-wrapper-connection.hpp"
#include "dbus-wrapper-serializer.hpp"

Spotify::SpotifyClient::SpotifyClient() {
    DBusWrapper::Bus::Bus a(DBUS_BUS_SESSION);
   // a.send<const char*>();
    auto reader = a.call_with_reply<const char *>("org.mpris.MediaPlayer2.spotify","/org/mpris/MediaPlayer2", "org.freedesktop.DBus.Properties", "Get","org.mpris.MediaPlayer2.Player","PlaybackStatus");
    std::cout << std::get<0>(reader.get()) << std::endl;
}