#include <assert.h>
#include <iostream>
#include <type_traits>
#include <memory>
#include <utility>

template <typename T>
class Number{

		static_assert(std::is_same_v<T,int> || std::is_same_v<T, double> || std::is_same_v<T, float>,"Type only accepts int or double" );

		private:
				T value;

		public:
				Number(T value): value(value){};
				
				constexpr T calculate(){
						return value;
				}
};

template <typename T>
class Addition{

		private:
				std::unique_ptr<Number<T>>left;
				std::unique_ptr<Number<T>>right;
		public:
				Addition(std::unique_ptr<Number<T>> left,std::unique_ptr<Number<T>> right):left(std::move(left)),right(std::move(right)){
				};

				constexpr T calculate(){

						return left->calculate() + right->calculate();
				}

};

template <typename T>
class Multiplication{

		private:
				std::unique_ptr<Number<T>>left;
				std::unique_ptr<Number<T>>right;
		public:
				Multiplication(std::unique_ptr<Number<T>> left,std::unique_ptr<Number<T>> right):left(std::move(left)),right(std::move(right)){
				};

				constexpr T calculate(){

						return left->calculate() * right->calculate();
				}

};

template <typename T>
class Division{

		private:
				std::unique_ptr<Number<T>>left;
				std::unique_ptr<Number<T>>right;
		public:
				Division(std::unique_ptr<Number<T>> left,std::unique_ptr<Number<T>> right):left(std::move(left)),right(std::move(right)){
				};

				constexpr T calculate(){

						return left->calculate() / right->calculate();
				}

};
int main(){


		auto five_plus_three =std::make_unique<Addition<int>>(
            std::make_unique<Number<int>>(3),
            std::make_unique<Number<int>>(5)
        );
		auto five_divided_three =std::make_unique<Division<float>>(
            std::make_unique<Number<float>>(3),
            std::make_unique<Number<float>>(5)
        );

		assert(five_plus_three->calculate() == 8);

		std::cout << five_divided_three->calculate() << std::endl;
		
		return 0;
}
