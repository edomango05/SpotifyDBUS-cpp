#ifndef SPOTIFY_DBUS_HPP
#define SPOTIFY_DBUS_HPP

#include <string>
#include <vector>
#include <functional>
#include <thread>

#include <dbus/dbus.h>
#include <unistd.h>

namespace Spotify
{
    struct SpotifyMetadata
    {
        char *m_trackid = nullptr;
        u_int64_t m_length = 0;
        char *m_artUrl = nullptr;
        char *m_album = nullptr;
        std::vector<const char *> m_albumArtist = std::vector<const char *>();
        std::vector<const char *> m_artist = std::vector<const char *>();
        double m_autoRating = 0;
        u_int32_t m_discNumber = 0;
        char *m_title = nullptr;
        u_int32_t m_trackNumber = 0;
        char *m_url = nullptr;
    };

    struct SpotifySignal
    {
        SpotifySignal(const char *_interface, const char *_name, void (*_callback)())
            : interface(_interface), name(_name), callback(_callback)
        {
        }
        const char *interface;
        const char *name;
        void (*callback)();
    };

    class SpotifyDBus
    {
    public:
        SpotifyDBus();
        const char *playbackStatus();
        const char *loopStatus();

        double rate();
        double minimumRate();
        double maximumRate();
        double volume();

        int64_t position();

        bool shuffle();
        bool canGoNext();
        bool canGoPrevious();
        bool canPlay();
        bool canPause();
        bool canSeek();
        bool canControl();

        const SpotifyMetadata metadata();

        void listener();
        void onSeeked(void (*callback)());

    private:
        DBusConnection *m_dbus_connection = nullptr;
        DBusError *m_dbus_error = nullptr;
        std::vector<const SpotifySignal> m_listeners = std::vector<const SpotifySignal>();
        std::thread m_thread;

        void addSignal(const char *_interface, const char *_name, void (*_callback)());
        
        DBusMessage *getDBusMethodMessage(const char *interface, const char *method);
        DBusMessage *getDBusSignalMessage(const char *interface, const char *method);
        DBusMessage *getProperty(const char *interface, const char *property);
        DBusMessage *sendMessage(DBusMessage *message);

        DBusMessageIter getDictionaryValue(DBusMessageIter *cursor);

        void readWholeArray(DBusMessageIter *cursor, std::vector<const char *> *array);
    };
}

#endif