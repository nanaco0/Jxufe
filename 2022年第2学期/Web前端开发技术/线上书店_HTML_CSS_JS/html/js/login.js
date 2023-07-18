function toggleForm() {
    var loginForm = document.getElementById("login-form");
    var registerForm = document.getElementById("register-form");
    
    if (loginForm.style.display === "none") {
      loginForm.style.display = "block";
      registerForm.style.display = "none";
    } else {
      loginForm.style.display = "none";
      registerForm.style.display = "block";
    }
  }
  
  function login() {
    var username = document.getElementById("login-username").value;
    var password = document.getElementById("login-password").value;
    
    // 在这里执行登录验证逻辑，并进行相应处理
    // 例如，向后端发送登录请求，验证用户名和密码的正确性
    // 如果验证成功，则跳转到用户主页，如果验证失败，则显示错误信息
  }
  
  function register() {
    var email = document.getElementById("register-email").value;
    var username = document.getElementById("register-username").value;
    var password = document.getElementById("register-password").value;
    
    // 在这里执行注册逻辑，并进行相应处理
    // 例如，向后端发送注册请求，创建新用户
    // 如果注册成功，则跳转到登录页面，如果失败，则显示错误信息
  }