# include "json.hpp"


string JSONPair::toString(void) const
{
    std::ostringstream out;

    out << "\"" << key << "\":" << valueToString();

    return out.str();
}

void JSONObject::addPair(const JSONPair& p)
{
    pairs.push_back(&p);
}

string JSONObject::toString(void) const
{
    std::ostringstream out;
    bool first = true;

    out << "{";

    for ( const JSONPair* p : pairs )
    {
	if ( ! first )
	{
	    out << ",";
	}

	first = false;
	out << p->toString();
    }

    out << "}";

    return out.str();
}

string JSONObjectList::valueToString(void) const
{
    std::ostringstream out;

    bool first = true;

    out << "[";

    for ( const JSONObject* o: objs )
    {
	if ( ! first )
	    out << ",";

	first = false;

	out << o->toString();
    }

    out << "]";

    return out.str();

}
