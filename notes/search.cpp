#include "search.h"
#include <QVector>

Search::Search() {}

int Search::Distance(QString str_1, QString str_2) {
    size_t length_1 = str_1.length();
    size_t length_2 = str_2.length();

    QVector<QVector<int>> matrix(length_1 + 1, QVector<int>(length_2 + 1, 0));


    for (size_t i = 0; i <= length_1; i++) {
        matrix[i][0] = i;
    }


    for (size_t j = 0; j <= length_2; j++) {
        matrix[0][j] = j;
    }


    for (size_t i = 1; i <= length_1; i++) {
        for (size_t j = 1; j <= length_2; j++) {
            int cost = (str_1[i - 1] == str_2[j - 1]) ? 0 : 1;

            matrix[i][j] = std::min({matrix[i - 1][j] + 1, matrix[i][j - 1] + 1,
                                     matrix[i - 1][j - 1] + cost});

            if (i > 1 && j > 1 && str_1[i - 1] == str_2[j - 2] &&
                str_1[i - 2] == str_2[j - 1]) {
                matrix[i][j] = std::min(matrix[i][j], matrix[i - 2][j - 2] + 1);
            }
        }
    }
    return matrix[length_1][length_2];
}

bool Search::TheSameString(QString str_1, QString str_2) {

    for (size_t i = 0; i < str_1.length(); i++) {
        if (str_1[i] == str_2[i])
            return true;
    }
    return false;
}
