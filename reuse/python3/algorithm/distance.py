def chebyshev_distance(point1, point2):
    return max(abs(point1[0] - point2[0]), abs(point1[1], point2[1]))


def euclidean_distance(point1, point2):
    return ((point1[0] - point2[0]) ** 2 + (point1[1] - point2[1]) ** 2) ** 0.5


def hamming_distance(x: int, y: int) -> int:
    return bin(x ^ y).count('1')


# Link: https://en.wikipedia.org/wiki/Levenshtein_distance


def levenshtein_distance(str1, str2):
    if not str1:
        return len(str2 or '') or 0
    if not str2:
        return len(str1 or '') or 0

    last = 0
    tmp = [0 for _ in range(len(str2) + 1)]
    result = 0
    for i in range(len(str1)):
        tmp[0] = i + 1
        last = i
        for j in range(len(str2)):
            if str1[i] == str2[j]:
                result = last
            else:
                result = 1 + min(last, tmp[j], tmp[j + 1])
            last = tmp[j + 1]
            tmp[j + 1] = result
    return result


def manhattan_distance(point1, point2):
    return abs(point1[0] - point2[0]) + abs(point1[1], point2[1])
