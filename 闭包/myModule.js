function myModule(){
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
    return {
        doSomething: doSomething,
        doOtherthing: doOtherthing
    }
}