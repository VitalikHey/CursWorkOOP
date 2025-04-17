#include "../../library/local_db/local_db.h"

LocalDatabase* LocalDatabase::instance = nullptr;
std::mutex LocalDatabase::mutex;