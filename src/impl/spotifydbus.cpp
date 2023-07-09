#include "spotifydbus.hpp"

using namespace Spotify;

SpotifyDBus::SpotifyDBus()
{
    m_dbus_connection = ::dbus_bus_get(DBUS_BUS_SESSION, m_dbus_error);
    if (m_dbus_connection == nullptr)
    {
        //@todo error handling
    }
}

const char *SpotifyDBus::playbackStatus()
{

    DBusMessage *response = getProperty("org.mpris.MediaPlayer2.Player", "PlaybackStatus");
    char *result;
    DBusMessageIter iter;
    DBusMessageIter sub;
    ::dbus_message_iter_init(response, &iter);
    ::dbus_message_iter_recurse(&iter, &sub);
    ::dbus_message_iter_get_basic(&sub, &result);
    //::dbus_message_get_args(response, m_dbus_error, DBUS_TYPE_STRING, &result, DBUS_TYPE_INVALID); @todo check for better args parsing
    return result;
}

const char *SpotifyDBus::loopStatus()
{

    DBusMessage *response = getProperty("org.mpris.MediaPlayer2.Player", "LoopStatus");
    char *result;
    DBusMessageIter iter;
    DBusMessageIter sub;
    ::dbus_message_iter_init(response, &iter);
    ::dbus_message_iter_recurse(&iter, &sub);
    ::dbus_message_iter_get_basic(&sub, &result);
    //::dbus_message_get_args(response, m_dbus_error, DBUS_TYPE_STRING, &result, DBUS_TYPE_INVALID); @todo check for better args parsing
    return result;
}

double SpotifyDBus::rate()
{

    DBusMessage *response = getProperty("org.mpris.MediaPlayer2.Player", "Rate");
    double result;
    DBusMessageIter iter;
    DBusMessageIter sub;
    ::dbus_message_iter_init(response, &iter);
    ::dbus_message_iter_recurse(&iter, &sub);
    ::dbus_message_iter_get_basic(&sub, &result);
    //::dbus_message_get_args(response, m_dbus_error, DBUS_TYPE_STRING, &result, DBUS_TYPE_INVALID); @todo check for better args parsing
    return result;
}

double SpotifyDBus::minimumRate()
{

    DBusMessage *response = getProperty("org.mpris.MediaPlayer2.Player", "MinimumRate");
    double result;
    DBusMessageIter iter;
    DBusMessageIter sub;
    ::dbus_message_iter_init(response, &iter);
    ::dbus_message_iter_recurse(&iter, &sub);
    ::dbus_message_iter_get_basic(&sub, &result);
    //::dbus_message_get_args(response, m_dbus_error, DBUS_TYPE_STRING, &result, DBUS_TYPE_INVALID); @todo check for better args parsing
    return result;
}

double SpotifyDBus::maximumRate()
{

    DBusMessage *response = getProperty("org.mpris.MediaPlayer2.Player", "MaximumRate");
    double result;
    DBusMessageIter iter;
    DBusMessageIter sub;
    ::dbus_message_iter_init(response, &iter);
    ::dbus_message_iter_recurse(&iter, &sub);
    ::dbus_message_iter_get_basic(&sub, &result);
    //::dbus_message_get_args(response, m_dbus_error, DBUS_TYPE_STRING, &result, DBUS_TYPE_INVALID); @todo check for better args parsing
    return result;
}
double SpotifyDBus::volume()
{

    DBusMessage *response = getProperty("org.mpris.MediaPlayer2.Player", "Volume");
    double result;
    DBusMessageIter iter;
    DBusMessageIter sub;
    ::dbus_message_iter_init(response, &iter);
    ::dbus_message_iter_recurse(&iter, &sub);
    ::dbus_message_iter_get_basic(&sub, &result);
    //::dbus_message_get_args(response, m_dbus_error, DBUS_TYPE_STRING, &result, DBUS_TYPE_INVALID); @todo check for better args parsing
    return result;
}

int64_t SpotifyDBus::position()
{

    DBusMessage *response = getProperty("org.mpris.MediaPlayer2.Player", "Position");
    double result;
    DBusMessageIter iter;
    DBusMessageIter sub;
    ::dbus_message_iter_init(response, &iter);
    ::dbus_message_iter_recurse(&iter, &sub);
    ::dbus_message_iter_get_basic(&sub, &result);
    //::dbus_message_get_args(response, m_dbus_error, DBUS_TYPE_STRING, &result, DBUS_TYPE_INVALID); @todo check for better args parsing
    return result;
}

bool SpotifyDBus::shuffle()
{

    DBusMessage *response = getProperty("org.mpris.MediaPlayer2.Player", "Shuffle");
    bool result;
    DBusMessageIter iter;
    DBusMessageIter sub;
    ::dbus_message_iter_init(response, &iter);
    ::dbus_message_iter_recurse(&iter, &sub);
    ::dbus_message_iter_get_basic(&sub, &result);
    //::dbus_message_get_args(response, m_dbus_error, DBUS_TYPE_STRING, &result, DBUS_TYPE_INVALID); @todo check for better args parsing
    return result;
}
bool SpotifyDBus::canGoNext()
{

    DBusMessage *response = getProperty("org.mpris.MediaPlayer2.Player", "CanGoNext");
    bool result;
    DBusMessageIter iter;
    DBusMessageIter sub;
    ::dbus_message_iter_init(response, &iter);
    ::dbus_message_iter_recurse(&iter, &sub);
    ::dbus_message_iter_get_basic(&sub, &result);
    //::dbus_message_get_args(response, m_dbus_error, DBUS_TYPE_STRING, &result, DBUS_TYPE_INVALID); @todo check for better args parsing
    return result;
}

bool SpotifyDBus::canGoPrevious()
{

    DBusMessage *response = getProperty("org.mpris.MediaPlayer2.Player", "CanGoPrevious");
    bool result;
    DBusMessageIter iter;
    DBusMessageIter sub;
    ::dbus_message_iter_init(response, &iter);
    ::dbus_message_iter_recurse(&iter, &sub);
    ::dbus_message_iter_get_basic(&sub, &result);
    //::dbus_message_get_args(response, m_dbus_error, DBUS_TYPE_STRING, &result, DBUS_TYPE_INVALID); @todo check for better args parsing
    return result;
}

bool SpotifyDBus::canPlay()
{

    DBusMessage *response = getProperty("org.mpris.MediaPlayer2.Player", "CanPlay");
    bool result;
    DBusMessageIter iter;
    DBusMessageIter sub;
    ::dbus_message_iter_init(response, &iter);
    ::dbus_message_iter_recurse(&iter, &sub);
    ::dbus_message_iter_get_basic(&sub, &result);
    //::dbus_message_get_args(response, m_dbus_error, DBUS_TYPE_STRING, &result, DBUS_TYPE_INVALID); @todo check for better args parsing
    return result;
}
bool SpotifyDBus::canPause()
{

    DBusMessage *response = getProperty("org.mpris.MediaPlayer2.Player", "CanPause");
    bool result;
    DBusMessageIter iter;
    DBusMessageIter sub;
    ::dbus_message_iter_init(response, &iter);
    ::dbus_message_iter_recurse(&iter, &sub);
    ::dbus_message_iter_get_basic(&sub, &result);
    //::dbus_message_get_args(response, m_dbus_error, DBUS_TYPE_STRING, &result, DBUS_TYPE_INVALID); @todo check for better args parsing
    return result;
}
bool SpotifyDBus::canSeek()
{

    DBusMessage *response = getProperty("org.mpris.MediaPlayer2.Player", "CanSeek");
    bool result;
    DBusMessageIter iter;
    DBusMessageIter sub;
    ::dbus_message_iter_init(response, &iter);
    ::dbus_message_iter_recurse(&iter, &sub);
    ::dbus_message_iter_get_basic(&sub, &result);
    //::dbus_message_get_args(response, m_dbus_error, DBUS_TYPE_STRING, &result, DBUS_TYPE_INVALID); @todo check for better args parsing
    return result;
}
bool SpotifyDBus::canControl()
{

    DBusMessage *response = getProperty("org.mpris.MediaPlayer2.Player", "CanControl");
    bool result;
    DBusMessageIter iter;
    DBusMessageIter sub;
    ::dbus_message_iter_init(response, &iter);
    ::dbus_message_iter_recurse(&iter, &sub);
    ::dbus_message_iter_get_basic(&sub, &result);
    //::dbus_message_get_args(response, m_dbus_error, DBUS_TYPE_STRING, &result, DBUS_TYPE_INVALID); @todo check for better args parsing
    return result;
}

const SpotifyMetadata SpotifyDBus::metadata()
{

    DBusMessage *response = getProperty("org.mpris.MediaPlayer2.Player", "Metadata");
    SpotifyMetadata data;
    DBusMessageIter iter;
    DBusMessageIter sub1;
    DBusMessageIter sub2;
    DBusMessageIter value_iter;
    ::dbus_message_iter_init(response, &iter);
    ::dbus_message_iter_recurse(&iter, &sub1);
    ::dbus_message_iter_recurse(&sub1, &sub2);
    value_iter = getDictionaryValue(&sub2);
    ::dbus_message_iter_get_basic(&value_iter, &data.m_trackid);
    value_iter = getDictionaryValue(&sub2);
    ::dbus_message_iter_get_basic(&value_iter, &data.m_length);
    value_iter = getDictionaryValue(&sub2);
    ::dbus_message_iter_get_basic(&value_iter, &data.m_artUrl);
    value_iter = getDictionaryValue(&sub2);
    ::dbus_message_iter_get_basic(&value_iter, &data.m_album);
    value_iter = getDictionaryValue(&sub2);
    readWholeArray(&value_iter, &data.m_albumArtist);
    value_iter = getDictionaryValue(&sub2);
    readWholeArray(&value_iter, &data.m_artist);
    value_iter = getDictionaryValue(&sub2);
    ::dbus_message_iter_get_basic(&value_iter, &data.m_autoRating);
    value_iter = getDictionaryValue(&sub2);
    ::dbus_message_iter_get_basic(&value_iter, &data.m_discNumber);
    value_iter = getDictionaryValue(&sub2);
    ::dbus_message_iter_get_basic(&value_iter, &data.m_title);
    value_iter = getDictionaryValue(&sub2);
    ::dbus_message_iter_get_basic(&value_iter, &data.m_trackNumber);
    value_iter = getDictionaryValue(&sub2);
    ::dbus_message_iter_get_basic(&value_iter, &data.m_url);
    return data;
}
void SpotifyDBus::listener()
{
    m_thread = std::thread(
        [&]()
        {
            while (true)
            {
                dbus_connection_read_write(m_dbus_connection, 0);
                DBusMessage *msg = dbus_connection_pop_message(m_dbus_connection);
                if (msg == nullptr)
                {
                    sleep(1);
                    continue;
                }
                for (SpotifySignal sig : m_listeners)
                {
                    if (dbus_message_is_signal(msg, sig.interface, sig.name))
                    {
                        sig.callback();
                    }
                }
                dbus_message_unref(msg);
            }
        });
}

void SpotifyDBus::onSeeked(void (*callback)())
{
    addSignal("org.mpris.MediaPlayer2.Player", "Seeked", callback);
}

DBusMessage *SpotifyDBus::getDBusMethodMessage(const char *interface, const char *method)
{
    return ::dbus_message_new_method_call("org.mpris.MediaPlayer2.spotify", "/org/mpris/MediaPlayer2", interface, method);
}
void SpotifyDBus::addSignal(const char *_interface, const char *_name, void (*_callback)())
{
    for (std::vector<const SpotifySignal>::const_iterator l = m_listeners.cbegin(); l < m_listeners.cend(); l++)
    {
        if (l->interface == _interface && l->name == _name)
        {
            m_listeners.erase(l);
        }
    }
    m_listeners.push_back(SpotifySignal(_interface, _name, _callback));
}
DBusMessage *SpotifyDBus::getDBusSignalMessage(const char *interface, const char *method)
{
    return ::dbus_message_new_signal("/org/mpris/MediaPlayer2", interface, method);
}
DBusMessage *SpotifyDBus::getProperty(const char *interface, const char *property)
{
    DBusMessage *message = getDBusMethodMessage("org.freedesktop.DBus.Properties", "Get");
    ::dbus_message_append_args(message, DBUS_TYPE_STRING, &interface, DBUS_TYPE_STRING, &property, DBUS_TYPE_INVALID);
    return sendMessage(message);
}
DBusMessage *SpotifyDBus::sendMessage(DBusMessage *message)
{

    return ::dbus_connection_send_with_reply_and_block(m_dbus_connection, message, DBUS_TIMEOUT_USE_DEFAULT, m_dbus_error);
}

DBusMessageIter SpotifyDBus::getDictionaryValue(DBusMessageIter *cursor)
{
    DBusMessageIter dict_iter;
    DBusMessageIter dict_sub;
    ::dbus_message_iter_recurse(cursor, &dict_iter);
    ::dbus_message_iter_next(&dict_iter);
    ::dbus_message_iter_recurse(&dict_iter, &dict_sub);
    ::dbus_message_iter_next(cursor);
    return dict_sub;
}

void SpotifyDBus::readWholeArray(DBusMessageIter *cursor, std::vector<const char *> *array)
{
    DBusMessageIter array_iter;
    ::dbus_message_iter_recurse(cursor, &array_iter);
    do
    {
        const char *read;
        ::dbus_message_iter_get_basic(&array_iter, &read);
        array->push_back(read);
    } while (::dbus_message_iter_has_next(&array_iter));
}