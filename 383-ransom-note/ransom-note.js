/**
 * @param {string} ransomNote
 * @param {string} magazine
 * @return {boolean}
 */
var canConstruct = function(ransomNote, magazine) {
    const mp = new Map();

    for(const ch of magazine){
        mp.set(ch, (mp.get(ch) || 0)+1);
    }

    for(const ch of ransomNote){
        if((mp.get(ch)||0) === 0){
            return false
        }
        mp.set(ch, mp.get(ch) -1);
    }
    return true;
};