#!/usr/bin/env python3

from time import perf_counter
from abc import ABC, abstractmethod

class Polynomial(ABC):
    def __init__(self, *coefficients):
        self.coefficients = list(coefficients)

    def __repr__(self):
        # TODO: Implement string representation.
        # Example: [1, 2, 3] -> "1 + 2x + 3x^2".

        repr = ""
        for degree, coef in enumerate(self.coefficients):
            if degree == 0:
                repr += f"{coef}"
            elif degree == 1:
                repr += f" + {coef}x"
            else:
                repr += f" + {coef}x^{degree}"
        return repr if repr else "0"
        
    def __add__(self, other):
        # TODO: Implement polynomial addition.
        # Hint: Pad shorter polynomial with zeros.
        result = []
        degree_self, degree_other = len(self.coefficients), len(other.coefficients)
        current = 0
        while current < min(degree_self, degree_other):
            result.append(self.coefficients[current] + other.coefficients[current])
            current +=1

        if current == degree_self:
            result + other.coefficients[current:]
        elif current < degree_self:
            result + other.coefficients[current:]
        
        return type(self)(*result)


    @abstractmethod
    def evaluate(self, x):
        pass


class StandardPolynomialEvaluator(Polynomial):
    def evaluate(self, x):
        # TODO: Implement standard evaluation.
        # P(x) = a0 + a1*x + a2*x^2 + ...
        if not isinstance(x, list):
            x = [x]
        res = []
        for val in x:
            tmp = 0.0
            #res.append(sum([coef * val**i for i, coef in enumerate(self.coefficients)]))
            for i, coef in enumerate(self.coefficients):
                tmp += coef * (val ** i)    
            res.append(tmp)
        return res if res else [0.0]

class HornerPolynomialEvaluator(Polynomial):
    def evaluate(self, x):
        # TODO: Implement Horner's rule.
        # P(x) = a0 + x*(a1 + x*(a2 + ...))
        if not isinstance(x, list):
            x = [x]
        res = []
        for val in x:
            tmp = 0.0
            for coef in reversed(self.coefficients):
                tmp = tmp * val + coef
            res.append(tmp)
        return res if res else [0.0]



# TODO: Implement measure_time decorator.
def measure_time(func):
    
    def wrapper(*args, **kwargs):
        t_start = perf_counter()
        res = func(*args, **kwargs)
        t_end = perf_counter()
        print(f"function {func.__name__}, elapsed time :{t_end - t_start}")
        return res
    return wrapper

@measure_time
def evaluate_polynomial(poly_evaluator, x_list):
    return [poly_evaluator.evaluate(x) for x in x_list]


if __name__ == "__main__":
    # Test basic operations.
    poly1 = StandardPolynomialEvaluator(1, 2, 3)
    print(f"poly1: {poly1}")
    
    poly2 = StandardPolynomialEvaluator(2, 3, 4)
    print(f"poly2: {poly2}")
    
    # Test evaluation.
    print(f"poly1(2) = {poly1.evaluate(2)}")  # Should be 1 + 4 + 12 = 17
    
    # TODO: Test addition.
    print(f"addition: {poly1 + poly2}")
    # TODO: Compare Standard vs Horner performance on 1000 points.
    vals = [i for i in range(1000)]

    print("evaluating with standard evaluation:")
    poly3 = StandardPolynomialEvaluator(*[15,18,36,42])
    evaluate_polynomial(poly3, vals)

    print("evaluating with horner evaluation:")
    poly4 = HornerPolynomialEvaluator(*[15,18,36,42])
    evaluate_polynomial(poly4, vals)