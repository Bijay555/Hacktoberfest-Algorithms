let BinarySearchTree = function (value) {
  const bNewtree = Object.create(BtreeMethod);
  bNewtree.value = value;
  bNewtree.left = null;
  bNewtree.right = null;


  return bNewtree;

};

let BtreeMethod = {};

BtreeMethod.insert = function (value) {
  let node = new BinarySearchTree(value);

  function recusion(element) {
      if (element.value >= node.value) {
          if (!element.left) {
              element.left = node;
          }
          else {
              recusion(element.left);
          }
      }
      else {
          if (!element.right) {
              element.right = node
          }
          else {
              recusion(element.right)
          }
      }
  }
  recusion(this);
}

BtreeMethod.contains = function (target) {
  let result = false;
  function recusion(element) {
      if (element.value > target) {
          if (element.left.value === target) {
              result = true;
              return;
          }
          else {
              recusion(element.left.value);
          }
      }
      if (element.value < target) {
          if (element.right.value === target) {
              result = true;
              return;
          }
          else {
              recusion(element.right.value)
          }
      }
  }
  recusion(this);
  return result;
}

BtreeMethod.depthFirstLog = function (func) {

  function recusion(element) {
      if (element.value) {
          func(element.value);
          if (element.left) {
              recusion(element.left);
          }
          if (element.right) {
              recusion(element.right);
          }
      }
  }
  recusion(this)
}