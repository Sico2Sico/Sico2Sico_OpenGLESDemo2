//
//  ViewController.swift
//  GLESDemo
//
//  Created by 德志 on 2019/4/25.
//  Copyright © 2019 com.aiiage.www. All rights reserved.
//

import UIKit
import OPenGLOBJ
import GLKit

class ViewController: GLKViewController {
    var context : EAGLContext!
    let rect = UIScreen.main.bounds
    let scale = UIScreen.main.scale
    override func viewDidLoad() {
        super.viewDidLoad()

        context = EAGLContext.init(api:EAGLRenderingAPI.openGLES3)
        if context == nil {
            context = EAGLContext.init(api:EAGLRenderingAPI.openGLES2)
        }

        let glView : GLKView  = self.view as!(GLKView)
        glView.context = context;
        glView.drawableDepthFormat = GLKViewDrawableDepthFormat.format24
        EAGLContext.setCurrent(context)


//        DraWCube.configuration()
//        DraWCube.setViewPortSize(Float(rect.width), height: Float(rect.height));

//        DrawLight.configuration()
//        DrawLight.setViewPortSize(Float(rect.width), height: Float(rect.height))


//        DrawBull.configuration()
//        DrawBull.setViewPortSize(Float(rect.width), height: Float(rect.height))

        DrawPicture.configuration();
        DrawPicture.setViewPortSize(Float(rect.width * scale), height: Float(rect.height * scale))
    }

    override func glkView(_ view: GLKView, drawIn rect: CGRect) {
//        DraWCube.draw()
//        DrawLight.draw()
//        DrawBull.draw()

        DrawPicture.draw(Float(rect.width*scale), height: Float(rect.height*scale))
    }
}
