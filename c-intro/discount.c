#include <stdio.h>
#include <ctype.h>

void discount(void);
float get_price(void);
int get_discount(void);
float calculate_discounted_price(float, float);
char user_response(void);
void result_output(float);

int main(void){

    //call discount()
    discount();
    return 0;
}

void discount(void){

    //variable declaration
    float f_price;
    float i_discount;
    float f_discounted_price;
    char ch;
    //Loop the cycle until user close the code
    do{
        //Price request
        f_price = get_price();
        //Discount request
        i_discount = get_discount();
        //Calculate discounted price
        f_discounted_price = calculate_discounted_price(f_price, i_discount);
        result_output(f_discounted_price);
        //Get user response
        ch = user_response();
    } while (ch != 'y'); 
}

float get_price(void){

    //Price request
    float a;
    printf("Please enter the price: ");
    scanf("%f", &a);
    return a;
}

int get_discount(void){

    //Discount request
    float a;
    printf("Please enter discount value: ");
    scanf("%f", &a);
    return a;
}

float calculate_discounted_price(float a, float b){

    //Calculate price
    float price;
    price = a * ( b / 100);
    return price;
}

char user_response(void){

    //Request user
    char ch;
    printf("Would you like to exit Y/N: ");
    scanf(" %c", &ch);
    return tolower(ch); 
}

void result_output(float result){

    //Result output
    printf("The discounted price is: %.2f \n", result);
}