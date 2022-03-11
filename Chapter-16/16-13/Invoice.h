#include <string>
using std::string;

class Invoice
{
public:
    Invoice( string vendorCode, string description, int priceForProduct, int countSalesProducts );
    void setVendorCode(string);
    void setDescription(string);
    void setPriceForProduct(int);
    void setCountSalesProducts(int);
    string getVendorCode();
    string getDescription();
    int getPriceForProduct();
    int getCountSalesProducts();
    int getInvoiceAmout();
private:
    string vendorCode;
    string description;
    int priceForProduct;
    int countSalesProducts;
};


