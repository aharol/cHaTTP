# ifndef RECEIVABLE_HPP
# define RECEIVABLE_HPP

# include "error.hpp"

enum class MessageOrigin {
    fromWebApp,
    fromMessageRelay,
    fromPersistence,
    fromBroker
};

/**
 * @brief Superclass for messages received from the outside.
 *
 * This class is used by the IPC part as returned object. Receivable objects are supposed
 * to be only temporary and soon to be casted to actual message objects.
 *
 */
class Receivable
{
public:
    virtual ~Receivable(void) = default;
};

# endif
