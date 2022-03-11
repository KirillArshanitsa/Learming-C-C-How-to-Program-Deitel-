#include "Invoice.h"

Invoice::Invoice(string code, string desc, int price, int count)
{
    vendorCode = code;
    description = desc;
    priceForProduct = price;
    countSalesProducts = count;
}

int Invoice::getCountSalesProducts()
{
    return countSalesProducts;
}

int Invoice::getPriceForProduct()
{
    return priceForProduct;
}

string Invoice::getDescription()
{
    return description;
}

string Invoice::getVendorCode()
{
    return vendorCode;
}

void Invoice::setVendorCode(string code)
{
    vendorCode = code;
}
void Invoice::setDescription(string desc)
{
    description = desc;
}
void Invoice::setPriceForProduct(int price)
{
    priceForProduct = price;
}

void Invoice::setCountSalesProducts(int count)
{
    countSalesProducts = count;
}


int Invoice::getInvoiceAmout()
{
    if (countSalesProducts < 0) {
        countSalesProducts = 0;
        return 0;
    }
    else{
        return countSalesProducts * priceForProduct;
    }
}