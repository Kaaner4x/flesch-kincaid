# Flesch-Kincaid Readability Test 📚

A simple yet effective C console application that analyzes English text to calculate its readability using the **Flesch Reading Ease** and **Flesch-Kincaid Grade Level** formulas.

## 📖 What is the Flesch-Kincaid Readability Test?

The **Flesch-Kincaid Readability Tests** are readability tests designed to indicate how difficult a reading passage in English is to understand. There are two tests: the Flesch Reading Ease, and the Flesch-Kincaid Grade Level. Although they use the same core measures (word length and sentence length), they have different weighting factors.

The algorithms work as follows:
1. **Count the elements:** The algorithm counts the total number of words, sentences, and syllables in the text.
2. **Flesch Reading Ease:** Calculates a score usually between 0 and 100. Higher scores indicate material that is easier to read; lower numbers mark passages that are more difficult to read.
   `206.835 - 1.015 * (Total Words / Total Sentences) - 84.6 * (Total Syllables / Total Words)`
3. **Flesch-Kincaid Grade Level:** Translates the score into a U.S. grade level, making it easier for teachers, parents, and others to judge the readability level of various books and texts.
   `0.39 * (Total Words / Total Sentences) + 11.8 * (Total Syllables / Total Words) - 15.59`

## 🎯 Project Purpose

The main objective of this project is to implement the **Flesch-Kincaid** algorithms in C and evaluate the readability level of the text inputted by the user.

When a user inputs a text passage, the application:
1. **Analyzes** the text to count words, sentences, and syllables using heuristic algorithms for English.
2. **Calculates** and displays the **Flesch Reading Ease** score and the **Flesch-Kincaid Grade Level**.

## 🚀 How to Run

Follow these steps to run the application on your local machine:

### Prerequisites
- A C compiler like [GCC](https://gcc.gnu.org/) (MinGW on Windows) must be installed on your system.

### Steps
1. **Clone the repository** (or download the source code):
   ```bash
   git clone https://github.com/Kaaner4x/flesch-kincaid.git
   ```
2. **Navigate to the project directory**:
   ```bash
   cd flesch-kincaid
   ```
3. **Compile the application**:
   ```bash
   gcc main.c -o FleschKincaid
   ```
4. **Run the application**:
   ```bash
   # On Windows
   .\FleschKincaid.exe
   
   # On Linux/macOS
   ./FleschKincaid
   ```
5. **Usage**: The console will prompt you to enter the text you want to analyze. Paste or type your text and press "Enter" to see the analysis results including word, sentence, and syllable counts, along with the readability scores.

## 📄 License

This project is licensed under the [MIT License](LICENSE). See the `LICENSE` file for details.
