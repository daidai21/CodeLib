/* ****************************************************************************
 * File Name   : exec_func_tuple.hpp
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 日  9/13 14:37:51 2020
 *************************************************************************** */


// TODO
// https://github.com/chxuan/cpp-utils/blob/master/invoke/invoke.hpp


#ifndef __EXEC_FUNC_TUPLE_HPP__
#define __EXEC_FUNC_TUPLE_HPP__

#include <tuple>
#include <utility>


template<typename FuncType, typename TupleType, std::size_t... IdxType>
decltype(auto) exec_func_tuple_impl(FuncType&& func, TupleType&& tpl, 
                               std::index_sequence<IdxType...>) {
  return func(std::get<IdxType>(std::forward<TupleType>(tpl))...);
}

template<typename FuncType, typename TupleType>
decltype(auto) exec_func_tuple(FuncType&& func, TupleType&& tpl) {
  constexpr auto size = std::tuple_size<typename std::decay<TupleType>::type>::value;
  return exec_func_tuple_impl(std::forward<FuncType>(func), 
                              std::forward<TupleType>(tpl),
                              std::make_index_sequence<size>{});
}


#endif // __EXEC_FUNC_TUPLE_HPP__
