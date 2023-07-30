#ifndef BETTER_DBUS_HPP
#define BETTER_DBUS_HPP

#include <vector>
#include <dbus-1.0/dbus/dbus.h>

namespace BetterDBus
{

    enum MessageType
    {
        INVALID = DBUS_MESSAGE_TYPE_INVALID,
        METHOD_CALL = DBUS_MESSAGE_TYPE_METHOD_CALL,
        METHOD_RETURN = DBUS_MESSAGE_TYPE_METHOD_RETURN,
        TYPE_ERROR = DBUS_MESSAGE_TYPE_ERROR,
        TYPE_SIGNAL = DBUS_MESSAGE_TYPE_SIGNAL
    };

    class Bus
    {
    public:
        Bus(DBusBusType type) : m_type(type)
        {
            m_connection = ::dbus_bus_get(type, m_error);
        }

        DBusBusType type() const
        {
            return m_type;
        }

    protected:
        DBusConnection *m_connection;
        DBusError *m_error;
        DBusBusType m_type;
    };

    class SessionBus : public Bus
    {
    public:
        SessionBus() : Bus(DBUS_BUS_SESSION){};
    };

    class SystemBus : public Bus
    {
    public:
        SystemBus() : Bus(DBUS_BUS_SYSTEM){};
    };

    class BusMessage
    {
    public:
        BusMessage(MessageType type) : m_type(type)
        {
            m_message = ::dbus_message_new(type);
        }
        MessageType type() const
        {
            return m_type;
        }

        template <typename... Args>
        void setArguments(Args...)
        {

            argumentIterator(Args...)
        }
        
    protected:
        DBusMessage* m_message;
        MessageType m_type;
    private:
        template <typename First, typename... Other>
        void argumentIterator(First first, Other...)
        {

            if (sizeof...(Other) != 0)
            {
                return argumentIterator<Other...>()
            }
        }

        template <typename T>
        void append(T arg)
        {
            //@todo invalid
        }

        template <typename T>
        void append(std::vector<T> arg)
        {
            //@todo invalid
        }

    };

    class MethodCall : BusMessage
    {
    public:
        MethodCall(const char *bus_name, const char *path, const char *iface, const char *method) : BusMessage(MessageType::METHOD_CALL){};
    };

};

#endif