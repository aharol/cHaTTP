# ifndef WEBAPP_PROTO_HPP
# define WEBAPP_PROTO_HPP

# include <string>

using std::string;

/**
 * @file webapp-proto.hpp
 *
 * Defining the protocol used to communicate with the FastCGI back-end web
 * application; it's described in /doc/protocols/webapp-message-broker.mkd.
 */

/**
 * @brief Channel ID type
 *
 * The channel id is used to identify a user's session; it should be a randomly generated
 * token of roughly 20 to 60 characters.
 *
 * The same string is used as an identifier for a session in the nginx delivery back-end.
 */
typedef string channel_id_t;

/**
 * @brief Command types available for communication with us.
 */
enum class WebappCommandCode {
    /// UREG - register a user
    registerUser,
    /// LOGIN - mark user as online
    logIn,
    /// LOGOUT - mark user as offline
    logOut,
    /// SNDMSG - Send a message to another user.
    sendMessage,
    /// UONLQ - Ask if specified user is online.
    isOnline
};

/**
 * @brief Response types sent by us.
 */
enum class WebappResponseCode {
    /// Registered user.
    registeredUser,
    /// Marked user as online.
    loggedIn,
    /// Marked user as offline.
    loggedOut,
    /// Accepted message for delivery (or didn't...)
    acceptedMessage,
    /// User status.
    isOnline
};

/******************************** Process incoming requests ********************************/

/**
 * @brief Class for web application requests to the message broker.
 */
struct WebappRequest
{
public:



private:
};


# endif