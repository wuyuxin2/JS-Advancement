/* 
        获取任意属性
       */
      function getStyle(obj, name) {
        if (window.getComputedStyle) {
          // 变量没找着报错，属性没找着返回undefined
          return getComputedStyle(obj, null)[name];
        } else {
          return obj.currentStyle[name];
        }
      }

      /* 
        所有正在执行的定时器都在这个变量中
       */
      // var timer;

      /* 
        执行简单动画的函数
          参数：
            obj:要执行动画的对象
            attr:要执行动画的样式,比如:left top width height
            target:执行动画的目标位置
            speed:移动的速度
            callback:回调函数，动画执行完毕以后执行
       */
      function move(obj, attr, target, speed, callback) {
        // 关闭上一个定时器
        clearInterval(obj.timer);
        // 获取当前位置
        var current = parseInt(getStyle(obj, attr));
        if(current > target){
          speed = - speed;
        }
        // 开启一个定时器，向obj添加一个timer属性，并保存它自己的定时器的标识
        obj.timer = setInterval(function() {
          // 获取box1的原来的left
          var oldValue = parseInt(getStyle(obj, attr));
          // 增加
          var newValue = oldValue + speed;
          if (speed < 0 && newValue < target || speed > 0 && newValue > target) {
            newValue = target;
          }
          // 将newValue射者给box1
          obj.style[attr] = newValue + "px";
          // 到达目标时，停止移动
          if (newValue == target) {
            // 达到目标关闭定时器
            clearInterval(obj.timer);
            // 动画执行完毕，调用回调函数
            callback && callback();
          }
        }, 30);
      }
