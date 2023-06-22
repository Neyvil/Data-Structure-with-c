#include <stdio.h>
#include <stdlib.h>

// Structure to represent a term in the polynomial
typedef struct Term {
    int coefficient;
    int power_x;
    int power_y;
    struct Term* next;
} Term;

// Function to create a new term
Term* createTerm(int coef, int power_x, int power_y) {
    Term* term = (Term*)malloc(sizeof(Term));
    term->coefficient = coef;
    term->power_x = power_x;
    term->power_y = power_y;
    term->next = NULL;
    return term;
}

// Function to add a term to the polynomial
void addTerm(Term** poly, int coef, int power_x, int power_y) {
    Term* term = createTerm(coef, power_x, power_y);

    if (*poly == NULL) {
        *poly = term;
    } else {
        Term* curr = *poly;

        // Traverse to the end of the list
        while (curr->next != NULL) {
            curr = curr->next;
        }

        curr->next = term;
    }
}

// Function to add two bivariate polynomials
Term* addPolynomials(Term* poly1, Term* poly2) {
    Term* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->power_x > poly2->power_x || (poly1->power_x == poly2->power_x && poly1->power_y > poly2->power_y)) {
            addTerm(&result, poly1->coefficient, poly1->power_x, poly1->power_y);
            poly1 = poly1->next;
        } else if (poly1->power_x < poly2->power_x || (poly1->power_x == poly2->power_x && poly1->power_y < poly2->power_y)) {
            addTerm(&result, poly2->coefficient, poly2->power_x, poly2->power_y);
            poly2 = poly2->next;
        } else {
            int sum_coef = poly1->coefficient + poly2->coefficient;
            if (sum_coef != 0) {
                addTerm(&result, sum_coef, poly1->power_x, poly1->power_y);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // Add remaining terms of poly1, if any
    while (poly1 != NULL) {
        addTerm(&result, poly1->coefficient, poly1->power_x, poly1->power_y);
        poly1 = poly1->next;
    }

    // Add remaining terms of poly2, if any
    while (poly2 != NULL) {
        addTerm(&result, poly2->coefficient, poly2->power_x, poly2->power_y);
        poly2 = poly2->next;
    }

    return result;
}

// Function to display a polynomial
void displayPolynomial(Term* poly) {
    if (poly == NULL) {
        printf("0");
    } else {
        while (poly != NULL) {
            printf("%dx^%d*y^%d ", poly->coefficient, poly->power_x, poly->power_y);
            poly = poly->next;
            
    }
}
}

// Function to free memory occupied by the polynomial
void freePolynomial(Term* poly) {
    Term* temp;

    while (poly != NULL) {
        temp = poly;
        poly = poly->next;
        free(temp);
    }
}

int main() {
    // Create and display the first polynomial: 3x^2*y^2 + 2x^1*y^1 + 4
    Term* poly1 = NULL;
    addTerm(&poly1, 3, 2, 2);
    addTerm(&poly1, 2, 1, 1);
    addTerm(&poly1, 4, 0, 0);
    addTerm(&poly1, 5, 3, 2);
    printf("Polynomial 1: ");
    displayPolynomial(poly1);
    printf("\n");

    // Create and display the second polynomial: 5x^2*y^2 - 2x^1*y^1 + 1
    Term* poly2 = NULL;
    addTerm(&poly2, 5, 2, 2);
    addTerm(&poly2, -2, 1, 1);
    addTerm(&poly2, 1, 0, 0);
    addTerm(&poly1, 5, 2, 3);
    printf("Polynomial 2: ");
    displayPolynomial(poly2);
    printf("\n");

    // Add the two polynomials and display the result: 8x^2*y^2 + 0x^1*y^1 + 5
    Term* result = addPolynomials(poly1, poly2);
    printf("Result: ");
    displayPolynomial(result);
    printf("\n");

    // Free memory occupied by the polynomials
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);

    return 0;
}
