// 工厂方法模式：一种具体工厂只生产一种具体产品
/**
 * @brief
 *  小明家有两个工厂，一个用于生产圆形积木，一个用于生产方形积木，请你帮他设计一个积木工厂系统，记录积木生产的信息。
 */

#include <iostream>
#include <vector>

// 抽象产品类
class Block {
 public:
  virtual void produce() = 0;
  virtual ~Block() = default;
};

// 具体产品类
class CircleBlock : public Block {
 public:
  void produce() override { std::cout << "Circle Block" << std::endl; }
  ~CircleBlock() = default;
};

class SquareBlock : public Block {
 public:
  void produce() override { std::cout << "Square Block" << std::endl; }
  ~SquareBlock() = default;
};

// 抽象工厂类
class BlockFactory {
 public:
  virtual Block* createBlock() = 0;
  virtual ~BlockFactory() = default;
};

// 具体工厂类
class CircleBlockFactory : public BlockFactory {
 public:
  Block* createBlock() override { return new CircleBlock(); }
  ~CircleBlockFactory();
};

class SquareBlockFactory : public BlockFactory {
 public:
  Block* createBlock() override { return new SquareBlock(); }
  ~SquareBlockFactory();
};

// 对外提供接口
class BlockFactorySystem {
 private:
  std::vector<Block*> blocks_;

 public:
  void produceBlock(BlockFactory* factory, int quantity) {
    if (!factory) {
      for (int i = 0; i < quantity; ++i) {
        Block* block = factory->createBlock();
        blocks_.push_back(block);
        block->produce();
      }
    }
  }

  const std::vector<Block*>& getBlocks() const { return blocks_; }

  ~BlockFactorySystem() {
    for (auto block : blocks_) {
      delete block;
    }
  }
};

int main() {
  BlockFactorySystem factory_system;
  std::vector<BlockFactory*> factorys = {new CircleBlockFactory(),
                                         new SquareBlockFactory()};
  int produce_count = 0;
  std::cin >> produce_count;

  for (int i = 0; i < produce_count; ++i) {
    std::string type;
    int quantity;
    std::cin >> type >> quantity;
    BlockFactory* factory = nullptr;
    if (type == "Circle") {
      factory = factorys[0];
    } else if (type == "Square") {
      factory = factorys[1];
    }
    factory_system.produceBlock(factory, quantity);
  }

  for (auto p : factorys) {
    delete p;
  }
  return 0;
}
