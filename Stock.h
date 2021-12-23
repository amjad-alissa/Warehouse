#ifndef WAREHOUSE_STOCK_H
#define WAREHOUSE_STOCK_H

class Stock {
private:
    // Attributes
    int articleNumber;
    int actualStock;
    int maximumStock;
    int consumption;

public:
    //Constructors
    Stock(int articleNumber, int actualStock, int maximumStock, int consumption);

    Stock();

    // Setters
    void setArticleNumber(int articleNumber);

    void setActualStock(int actualStock);

    void setMaximumStock(int maximumStock);

    void setConsumption(int consumption);

    // Getters
    int getArticleNumber() const;

    int getActualStock() const;

    int getMaximumStock() const;

    int getConsumption() const;
};


#endif //WAREHOUSE_STOCK_H
