(function(window){
    //  私有的数据
    var msg = 'my module'
    // 操作数据的函数
    function doSomething(){
        console.log('doSomething()' + msg.toUpperCase());
    }
    function doOtherthing(){
        console.log('doOtherthing()' + msg.toLowerCase());
    }
    // 向外暴露（给外部使用的方法）
    window.myModule2 = {
        doSomething: doSomething,
        doOtherthing: doOtherthing
    }
})(window)

// 匿名函数自调用