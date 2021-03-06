# include "broker-util.hpp"
# include "synchronization.hpp"

# include <algorithm>

using std::for_each;

std::fstream urandom;

/**
 * @brief Convert the number from a error string to a numeric value and remove it from the message.
 *
 * The broker produces many error string of the form "<code>,<message>", like "4,Persistence unreachable".
 * This function takes such a string, returns the number in front and removes the number and
 * the comma from the argument (output argument)
 *
 * @param message [output argument] The error message
 *
 * @returns The numeric error value.
 */
unsigned int removeErrorCode(string& message)
{
    unsigned int n = 0, i, len = message.size();
    bool number_found = false;

    for ( i = 0; i < len && message[i] != ','; i++ )
    {
	if ( message[i] >= 48 && message[i] <= 57 ) // a.k.a. isDigit()
	{
	    n *= 10;
	    n += message[i] - 48;
	    number_found = true;
	}
    }

    message = number_found ? message.substr(i+1) : message;

    return n;
}

void initializeUrandomSource(void)
{
    urandom.open("/dev/urandom",std::ios_base::in);
}

std::string generateChannelId(void)
{
    char channel_id[65];

    channel_id[64] = 0;

    unique_lock<mutex> urandom_lock(urandom_mutex);
	urandom.get(channel_id,64);
    urandom_lock.unlock();

    for ( unsigned int i = 0; i < 64; i++ )
    {
	channel_id[i] = 'a' + ( (channel_id[i]  < 0 ? - channel_id[i] : channel_id[i]) % 26 );
    }

    return std::string(channel_id);
}

void stderrWrite(void)
{
    return;
}

template<>
const string removeStringNewlines(const string orig_msg)
{
    string msg = orig_msg;
    for_each(msg.begin(),msg.end(),[](char& c) { c == '\n' ? c = ' ' : 0; });

    return msg;
}
