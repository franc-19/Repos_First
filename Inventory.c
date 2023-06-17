#include <stdio.h>
#include <string.h>

struct Product
{
	char name[50];
	double price;
	int quantity;
};

void displayProducts(struct Product products[], int size)
{
	printf("Available Products:\n");
	printf("......................................\n");
	printf("%-20s%-10s%-10s\n", "Product Name", "Price", "Quantity");
	printf("......................................\n");

	for (int i = 0; i < size; i++)
		printf("%-20s%-10.2f%-10d\n", products[i].name, products[i].price, products[i].quantity);
	printf("\n");
}

int main()
{
	struct Product products[] = {
		{"Amoxyl", 10.00, 50},
		{"Panadol", 5.00, 100},
		{"Brufen", 15.00, 25},
		{"Quinin", 8.00, 75},
		{"metronidazole", 9.00, 45}
	};
	int size = sizeof(products) / sizeof(products[0]);

	printf("\n       FRANC'S ONLINE PHAMARCY\n");
	displayProducts(products, size);
	char productName[50];
	int quantity;

	/* Product selection */
	printf("Enter the name of the product:");
	fgets(productName, sizeof(productName), stdin);
	productName[strcspn(productName, "\n")] = '\0'; /* remove new line char */

	/* Quantity selection */
	printf("Enter the quantity: ");
	scanf("%d", &quantity);

	/* Find the selected product */
	struct Product selectedProduct;
	int productFound = 0;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(products[i].name, productName) == 0)
		{
			selectedProduct = products[i];
			productFound = 1;
			break;
		}
	}
	
	if (!productFound)
	{
		printf("Product not found.\n");
		return (0);
	}

	if (quantity > selectedProduct.quantity)
	{
		printf("Insufficeient stock.\n");
		return (0);
	}

	/* Calculate total price */
	double totalPrice = selectedProduct.price * quantity;

	/* Update product quantity */
	selectedProduct.quantity -= quantity;

	/* Update the products array with the updated product quantity */
	for (int i = 0;	i < size; i++)
	{
		if (strcmp(products[i].name, selectedProduct.name) == 0)
		{
			products[i].quantity = selectedProduct.quantity;
			break;
		}
	}

	/* Display order details */
	printf("\nOrder Details:\n");

	printf("....................................................\n");
	printf("%-20s%-10s%-10s%-10s\n", "ProductName", "Price", "Quantity", "Total Price");

	printf("....................................................\n");
	printf("%-20s%-10.2f%-10d%-10.2f\n", selectedProduct.name, selectedProduct.price, quantity, totalPrice);
	printf("\n");

	return (0);
}





