void updateInv(vector<InventoryRec> &inventory, InventoryRec newItem) {

  for (auto &item : inventory) {
    if (item.name == newItem.name && item.num == newItem.num) {
      item.qty += newItem.qty;
      return;
    }
  }

  // If the item is not found in the inventory, add a new item
  inventory.push_back(newItem);
}
