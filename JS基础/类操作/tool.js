// 定义一个函数，用来向一个元素中添加指定的class属性值
    /* 
        参数：
            obj 要添加class属性的元素
            cn 要添加的class值
    */
   function addClass(obj, cn){
    if(!hasClass(obj, cn)){
        obj.className += " " + cn; 
    }
}
/* 
    判断元素中是否含有指定class
    创建一个正在表达式
    如果有返回true，没有返回false
        参数：
            obj 
            cn
*/
function hasClass(obj, cn){
    // var reg = /\bb2\b/;
    //构造函数
    var reg = new RegExp("\\b"+cn+"\\b");
    return reg.test(obj.className);
}
/*
    删除指定的class
        参数： 
            obj
            cn
 */
function removeClass(obj, cn){
    var reg = new RegExp(" \\b" + cn +"\\b");
    obj.className = obj.className.replace(reg, "");
}
/* 
    切换一个类
        有，删除
        无，添加
*/
function toggleClass(obj, cn){
    if(hasClass(obj, cn)){
        removeClass(obj, cn);
    }else{
        addClass(obj, cn);
    }
}