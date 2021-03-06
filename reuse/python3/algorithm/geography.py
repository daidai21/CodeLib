#!/usr/bin/env python3


def haversine_formula(origin:tuple, destination:tuple) -> float:
    """
    Unit: KM
    Input:
        origin     : tuple(latitude, longitude)
        destination: tuple(latitude, longitude)
    Output:
        distance of float type
    Ref:
        https://en.wikipedia.org/wiki/Haversine_formula
    Disadvantages:
        The greater the center angle, the greater the error.
    """
    from math import radians, sin, cos, sqrt, asin

    lat_ori, lon_ori = origin
    lat_des, lon_des = destination
    radius = float(6371)  # km, radius of the earth

    lat_ori = radians(lat_ori)
    lon_ori = radians(lon_ori)
    lat_des = radians(lat_des)
    lon_des = radians(lon_des)

    dis_lat = lat_des - lat_ori
    dis_lon = lon_des - lon_ori

    tmp = sin(dis_lat * 0.5) ** 2 + cos(lat_ori) * cos(lat_des) * sin(dis_lon * 0.5) ** 2
    d = 2 * radius * asin(sqrt(tmp))

    return d


if __name__ == "__main__":
    d = haversine_formula(tuple([45.7597, 4.8422]), tuple([48.8567, 2.3508]))
    assert(round(d, 3) == round(392.2172595594006, 3))

    print(haversine_formula(tuple([0, 0]), tuple([180, 180])))
    print(haversine_formula(tuple([0, 0]), tuple([90, 90])))
