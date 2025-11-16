#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <iterator> // for back_inserter

class Book {
public:
  std::string title;
  std::string author;
  std::string genre;
  unsigned int publication_year;
};

void print(const std::vector<Book> &books) {
  for (const Book &book : books) {
    std::cout << "  Title: " << book.title << " | Author: " << book.author
              << " | Genre: " << book.genre
              << " | Year: " << book.publication_year << std::endl;
  };
  std::cout << '\n';
}

bool comp_by_year_ascending(const Book& b1, const Book& b2) {
    return b1.publication_year < b2.publication_year;
  };


class CompByAuthorAscending{
  public:
  bool operator()(const Book& b1, const Book& b2) {
    return b1.author < b2.author;
  };
};


int main() {
  // Define a list of books.
  std::vector<Book> books = {
      {"Go set a watchman", "Harper Lee", "Fiction", 2015},
      {"Animal farm", "George Orwell", "Satire", 1945},
      {"To kill a mockingbird", "Harper Lee", "Fiction", 1960},
      {"1984", "George Orwell", "Science fiction", 1949},
      {"Pride and prejudice", "Jane Austen", "Romance", 1813},
      {"Sense and sensibility", "Jane Austen", "Romance", 1811}};

  std::cout << "Original list of books:" << std::endl;
  print(books);


  // - - - - - my code - - - - - //
  

  // Sort in ascending order by year. using function pointer
  std::cout << "Sorting books in ascending order wrt publication year:\n";
  std::sort(books.begin(), books.end(), comp_by_year_ascending);
  print(books);
  

  // Sort in descending order by year. using lambda funciton
  std::cout << "Sorting books in descending order wrt publication year:\n";
  std::sort(books.begin(), books.end(), [](const Book& b1, const Book& b2){
                      return b1.publication_year >= b2.publication_year;});
  print(books);


  // Sort in ascending order by author name. using functor
  std::cout << "Sorting books in ascending order wrt author:\n";
  std::sort(books.begin(), books.end(), CompByAuthorAscending{});
  print(books);

  // Filter books by author.
  std::cout << "Filtering books based on an author:\n";
  const std::string author = "George Orwell";
  std::vector<Book> filtered;
  filtered.reserve(books.size());
  std::copy_if(books.begin(), books.end(), std::back_inserter(filtered), [author](const Book& b) {
    return b.author == author;
  });
  print(filtered);

  return 0;
}
