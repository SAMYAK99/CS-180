class SetModel<T> {
  T? item;
  String? error;
  bool loading;

  SetModel({
    this.item,
    this.error,
    this.loading = false,
  });
}
