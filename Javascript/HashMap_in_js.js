class NaiveHashMap {

  constructor(initialCapacity = 2) {
    this.buckets = new Array(initialCapacity);
  }

  set(key, value) {
    const index = this.getIndex(key);
    this.buckets[index] = value;
  }

  get(key) {
    const index = this.getIndex(key);
    return this.buckets[index];
  }

  hash(key) {
    return key.toString().length;
  }

  getIndex(key) {
    const indexHash = this.hash(key);
    const index = indexHash % this.buckets.length;
    return index;
  }
}

// Usage:
const assert = require('assert');
const hashMap = new NaiveHashMap();

hashMap.set('cat', 2);
hashMap.set('rat', 7);
hashMap.set('dog', 1);
hashMap.set('art', 8);

console.log(hashMap.buckets);
/*
  bucket #0: <1 empty item>,
  bucket #1: 8
*/

assert.equal(hashMap.get('art'), 8); // this one is ok
assert.equal(hashMap.get('cat'), 8); // got overwritten by art 😱
assert.equal(hashMap.get('rat'), 8); // got overwritten by art 😱
assert.equal(hashMap.get('dog'), 8); // got overwritten by art 😱
