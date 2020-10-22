
const getNum = (num, index) => {
  const strNumber = String(num);
  let end = strNumber.length-1;
  const foundNumber = strNum[end - index];
  
  foundNum === undefined? 0: foundNumber;
  return;
}

const largestNumber = array => {
  let largest = "";
  
  array. forEach(x => {
    const strNumber = String(x);
    
    if(strNumber.length > largest.length) largest =  strNumber
  })
  return largest.length;
}

const radix_sort = array => {
  let maxLen = largestNumber(array);
  for (let i = 0; i < maxlen; i++){
    let buckets = Array.from({ length: 10 },()=>{})
    
    for (let j = 0; j < array.length; j++){
      let num = getNum(array[j], i);
      
      if(num !== undefined) buckets[num].push(array[j]); 
   };
   array = buckets.flat();
  };
  return array;
};


let unsortedArr = [2,4,6,2,123,45,7,3,14,7,6,34,4657345,42,] 
console.log(radix_sort(unsortedArr));
