# ifndef MESSAGE_RELAY_HPP
# define MESSAGE_RELAY_HPP

# include <string>

# include "sequence-number.hpp"

using std::string;

class MessageForRelay
{
public:
    MessageForRelay(const string& mesg, const string& chan_id);

    string toString(void);
private:
    sequence_t seq_num;
    string message;
    string channel_id;
};

class MessageRelayResponse
{
public:
    MessageRelayResponse(const string& response);
private:
    sequence_t seq_num;
    bool status;
};

# endif