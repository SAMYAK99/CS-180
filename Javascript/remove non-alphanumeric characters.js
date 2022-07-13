// remove all non-alphanumeric characters
let newarr = ''

const removechar = (text) => {
  let rege = /[a-z0-9]/gi;
  let tes = text.match(rege);
  newarr = tes;
}
// input 
removechar("h_df");