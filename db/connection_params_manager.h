#ifndef DB_CONNECTION_PARAMS_MANAGER_H
#define DB_CONNECTION_PARAMS_MANAGER_H

#include <QVector>
#include "db/connection_parameters.h"

namespace meow {
namespace db {

class ConnectionParamsManager
{
public:
    ConnectionParamsManager();
    void load();
    int count() const;
    const ConnectionParameters& at(int index) const;
    ConnectionParameters& at(int index);
    const ConnectionParameters& createNewParams();
    void updateAndSaveParamsAt(int index, const ConnectionParameters &connectionParams);
    void removeParamsAndSave(const ConnectionParameters &params);
    bool renameParamsAndSave(
        ConnectionParameters &params,
        const QString& newName);
    int indexOfParams(const ConnectionParameters & params);
private:
    QVector<ConnectionParameters> _params;
    QString findNextFreeSessionName();

    int add(const ConnectionParameters &connectionParams);
    void saveParams(const ConnectionParameters & params);
    void removeSavedParams(const ConnectionParameters & params);
};

} // namespace db
} // namespace meow

#endif // DB_CONNECTION_PARAMS_MANAGER_H
