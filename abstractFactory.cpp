// 抽象工厂模式：一种具体工厂生产多种产品
#include <iostream>
#include <string>

// 抽象产品接口
class Chair {
 public:
  virtual void showInfo() = 0;
  virtual ~Chair();
};

class Sofa {
 public:
  virtual void displayInfo() = 0;
  virtual ~Sofa();
};

// 具体产品类
class ModernChair : public Chair {
 public:
  void showInfo() override { std::cout << "modern chair" << std::endl; }
};

class ClassicalChair : public Chair {
 public:
  void showInfo() override { std::cout << "classical chair" << std::endl; }
};

class ModernSofa : public Sofa {
 public:
  void displayInfo() override { std::cout << "modern sofa" << std::endl; }
};

class ClassicalSofa : public Sofa {
 public:
  void displayInfo() override { std::cout << "classical sofa" << std::endl; }
};

// 定义抽象工厂类
class FurnitureFactory {
 public:
  virtual Chair* createChair() = 0;
  virtual Sofa* createSofa() = 0;
  virtual ~FurnitureFactory();
};

// 实现具体工厂类
class ModernFurnitureFactory : public FurnitureFactory {
 public:
  Chair* createChair() override { return new ModernChair(); }
  Sofa* createSofa() override { return new ModernSofa(); }
};

class ClassicalFurnitureFactory : public FurnitureFactory {
 public:
  Chair* createChair() override { return new ClassicalChair(); }
  Sofa* createSofa() override { return new ClassicalSofa(); }
};
// 在客户端中使用抽象工厂和抽象产品
int main() {
  int n;
  std::cin >> n;

  // 处理订单
  for (int i = 0; i < n; ++i) {
    // 读取家具类型
    std::string type;
    std::cin >> type;

    FurnitureFactory* factory = nullptr;
    if (type == "modern") {
      factory = new ModernFurnitureFactory();
    } else if (type == "classical") {
      factory = new ClassicalFurnitureFactory();
    }

    Chair* chair = factory->createChair();
    Sofa* sofa = factory->createSofa();

    chair->showInfo();
    sofa->displayInfo();

    delete factory;
    delete chair;
    delete sofa;
  }

  return 0;
}
