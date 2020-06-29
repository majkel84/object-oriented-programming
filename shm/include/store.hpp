#pragma once

#include "cargo.hpp"
#include "player.hpp"
#include "time.hpp"

enum class Response {
    done,
    lack_of_money,
    lack_of_cargo,
    lack_of_space
};

class Store : public Observer{
public:
    Store();
    Store(Time* time);
    ~Store();
    //     ~Your() {
    //         time_->removeObserver(this);
    //     }

    Response buy(Cargo* cargo, size_t amount, Player* player);
    Response sell(Cargo* cargo, size_t amount, Player* player);
    void nextDay() override;
    std::vector<cargoPtr> cargo_;

    // dopisać składowe - towar jaki sklep przetrzymuje i obsługa nextday ;)
private:
    Time* time_;
};
