#include <string>
#include "pq.h"
#include <ctime>
#include <iostream>


struct order{
    std::string namn;
    double pris;
};

struct buyComp{
    auto operator()(order ord1, order ord2){
        return ord1.pris < ord2.pris;
    }
};

struct sellComp{
    auto operator()(order ord1, order ord2){    
        return ord2.pris < ord1.pris;
    }
};

double randomNr(){
    double b = rand() % 16 + 15;
    double c = rand() % 16 + 15;
    return (b + c) / 2;
}

int main(){

    buyComp bComp;
    sellComp sComp;
    pq<order, buyComp> buyOrders(bComp);
    pq<order, sellComp> sellOrders(sComp);

    srand(time(0));
    for (size_t i = 0; i <= 6; i++) {
        order buyOrder{"Erik Pendel", randomNr()};
        order sellOrder{"Erik Pendel", randomNr()};
        buyOrders.push(buyOrder);
        sellOrders.push(sellOrder);
    }
    
    for (size_t i = 0; i <= 6; i++) {
        order buyOrder{"Jarl Wallenburg", randomNr()};
        order sellOrder{"Jarl Wallenburg", randomNr()};
        buyOrders.push(buyOrder);
        sellOrders.push(sellOrder);
    }

    for (size_t i = 0; i <= 6; i++) {
        order buyOrder{"Joakim von Anka", randomNr()};
        order sellOrder{"Joakim von Anka", randomNr()};
        buyOrders.push(buyOrder);
        sellOrders.push(sellOrder); 
    }

    buyOrders.print();
    std::cout << "SELL ORDERS: \n";
    sellOrders.print();

    while(!buyOrders.empty() && !sellOrders.empty()){
        if((buyOrders.top().pris >= sellOrders.top().pris) && sellOrders.top().namn != buyOrders.top().namn){
            std::cout << "Order made: " << buyOrders.top().namn << " bought from " << sellOrders.top().namn << " for price " << sellOrders.top().pris << "\n"
            << "Byers price: " << buyOrders.top().pris << " Sellers price: " << sellOrders.top().pris << "\n";
            sellOrders.pop();
            buyOrders.pop();
        } else {
            buyOrders.pop();
            sellOrders.pop();
        }
    }

}