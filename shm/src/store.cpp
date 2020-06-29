#include "store.hpp"

Store::Store() {
}

Store::Store(Time *time)
    : time_(time) {
    time_ -> addObserver(this);
}

Store::~Store() {
    time_ -> removeObserver(this);
}

Response Store::buy(Cargo* cargo, size_t amount, Player* player) {
    int totalPrice = cargo->getPrice() * amount;

    if (player->getAvailableSpace() < amount)
        return Response::lack_of_space;

    else if (cargo->getAmount() < amount)
        return Response::lack_of_cargo;

    else if (totalPrice > player->getMoeny())
        return Response::lack_of_money;
    std::shared_ptr<Cargo> cargoPtr(cargo);
    player->getShip()->load(cargoPtr);
    player->subtractMoney(totalPrice);
    cargo -= amount;
    return Response::done;
}

Response Store::sell(Cargo* cargo, size_t amount, Player* player) {
    if (player->getShip()->FindMatchCargo(cargo)->getAmount() < amount)
        return Response::lack_of_cargo;

    cargo += amount;

    size_t money = amount * cargo->getPrice();
    player->addMoney(money);

    return Response::done;
}

void Store::nextDay() {
    for (auto el : cargo_) {
        el -> nextDay();
    }
}
