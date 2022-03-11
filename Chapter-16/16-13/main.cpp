#include <iostream>

using std::cout;
using std::endl;

#include "Invoice.h"

int main()
{
    Invoice myInvoice("Product1", "About product1", 20, 3);

    cout << "Test before changes:\ngetVendorCode() = " << myInvoice.getVendorCode() <<
    "\ngetPriceForProduct() = " << myInvoice.getPriceForProduct() << "\ngetDescription() = " << myInvoice.getDescription() <<
    "\ngetInvoiceAmout() = " << myInvoice.getInvoiceAmout() << "\ngetInvoiceAmout() = " << myInvoice.getInvoiceAmout() << endl;

    myInvoice.setVendorCode("ChangeProduct");
    myInvoice.setCountSalesProducts(-1);
    myInvoice.setDescription("Changes about product");
    myInvoice.setPriceForProduct(7);

    cout << "\nTest after changes:\ngetVendorCode() = " << myInvoice.getVendorCode() <<
         "\ngetPriceForProduct() = " << myInvoice.getPriceForProduct() << "\ngetDescription() = " << myInvoice.getDescription() <<
         "\ngetInvoiceAmout() = " << myInvoice.getInvoiceAmout() << "\ngetInvoiceAmout() = " << myInvoice.getInvoiceAmout() << endl;
}
