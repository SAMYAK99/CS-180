class SetModelList<T> {
  Set<T>? items = {};
  String? error;
  bool loading;
  bool loadingLoadmore;
  bool listHasEnded;
  int limit;
  int start;

  SetModelList({
    this.items,
    this.error,
    this.loading = false,
    this.loadingLoadmore = false,
    this.listHasEnded = false,
    this.limit = 20,
    this.start = 0,
  });
}
