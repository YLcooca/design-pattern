// 购物车单例 https://kamacoder.com/problempage.php?pid=1074
/**
 * 小明去了一家大型商场，拿到了一个购物车，并开始购物。请你设计一个购物车管理器，记录商品添加到购物车的信息（商品名称和购买数量），
 * 并在购买结束后打印出商品清单。（在整个购物过程中，小明只有一个购物车实例存在）。
 * 输入描述
 * 输入包含若干行，每行包含两部分信息，分别是商品名称和购买数量。商品名称和购买数量之间用空格隔开。
 * 输出描述
 * 输出包含小明购物车中的所有商品及其购买数量。每行输出一种商品的信息，格式为
 * "商品名称 购买数量"。
 */
#include <iostream>
#include <map>
#include <string>

class Cart {
 public:
  // 单例模式的精华在此处
  static Cart& getInstance() {
    static Cart instance;
    return instance;
  }

  void addToCart(std::string name, int num) { cart_[name] += num; }
  void print() {
    for (auto& it : cart_) {
      std::cout << it.first << " " << it.second << "\n";
    }
  }

 private:
  Cart() = default;
  std::map<std::string, int> cart_;
};