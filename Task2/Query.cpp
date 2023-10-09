#include "Query.h"

Query::Query()
{

}

Query::~Query()
{
    // if(queryObject != nullptr)
    delete queryObject;
}
